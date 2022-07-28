#include "pass.hpp"
ssa *ssaIR = new ssa();
/********************************************SSA***********************************/
/**为了后续优化需要先将IR转换成静态单赋值类型的IR
 * 这里用到的是Tarjan算法
 *
 */
void ssa::init()
{
    dfscnt = 0;
    semi.clear();
    parent.clear();
    bucket.clear();
    vertex.clear();
}
void ssa::dfsLT(DomTreenode *node)
{
    semi[node] = ++dfscnt;
    vertex.push_back(node);
    BasicBlock *db = node->block;
    for (auto i : db->succBlock)
    {
        if (!block2dom[i])
        {
            block2dom[i] = new DomTreenode();
            block2dom[i]->block = i;
        }
        DomTreenode *nx = block2dom[i];
        if (!semi[nx])
        {
            parent[nx] = node;
            dfsLT(nx);
        }
    }
}
void ssa::compress(DomTreenode *v)
{
    if (ancestor[ancestor[v]] != 0)
    {
        compress(ancestor[v]);
        if (semi[label[ancestor[v]]] < semi[label[v]])
        {
            label[v] = label[ancestor[v]];
        }
        ancestor[v] = ancestor[ancestor[v]];
    }
}
DomTreenode *ssa::eval(DomTreenode *v)
{
    // eval: 在并查集中到根路径中semi最小的点
    if (ancestor[v] == 0)
        return v; //如果是根
    else
    {
        compress(v);     //进行路径压缩
        return label[v]; //返回label
    }
}

void ssa::build_domtree(BasicBlock *s)
{
    init();
    block2dom[s->domBlock[0]] = new DomTreenode();
    block2dom[s->domBlock[0]]->block = s->domBlock[0];
    DomTreenode *root = block2dom[s->domBlock[0]];
    root->func = s->Func;
    DomRoot.push_back(root);
    dfsLT(root);

    ancestor[root] = 0;
    for (auto i : vertex)
        label[i] = i;
    for (int i = vertex.size() - 1; i > 0; i--)
    {
        auto w = vertex[i];
        BasicBlock *wb = w->block;
        for (auto vb : wb->pioneerBlock)
        {
            DomTreenode *v = block2dom[vb];
            DomTreenode *u = eval(v);
            if (semi[u] < semi[w])
                semi[w] = semi[u];
        }
        auto t1 = semi[w];
        auto t2 = vertex[t1 - 1];
        bucket[t2].push_back(w);
        ancestor[w] = parent[w];
        if (bucket[parent[w]].size() == 0)
            continue;
        for (auto i = bucket[parent[w]].begin(); i < bucket[parent[w]].end(); i++)
        {
            auto v = *i;
            i = bucket[parent[w]].erase(i) - 1;
            DomTreenode *u = eval(v);
            if (semi[u] < semi[v])
                v->idom = u;
            else
                v->idom = parent[w];
        }
    }

    for (auto w : vertex)
    {
        if (w == vertex.front())
            continue;
        if (w->idom != vertex[semi[w] - 1])
        {
            w->idom = w->idom->idom;
        }
        w->idom->son.push_back(w);
    }
    vertex[0]->idom = nullptr;
}

void ssa::compute_boundary(BasicBlock *b)
{
    if (b->pioneerBlock.size() >= 2)
    {
        for (auto i : b->pioneerBlock)
        {
            auto runner = i;
            while (runner != block2dom[b]->idom->block)
            {
                ssaIR->DomainFrontier[runner].insert(b);
                runner = block2dom[runner]->idom->block;
            }
        }
    }
}


void ssa::getAllValue()
{
    /*遍历符号表得到所有的Symbol*/
}



void ssa::addAssbyBlock(Symbol *val, BasicBlock *b)
{
    ssaIR->AssignbyBlock[val].push_back(b);
}

void ssa::setAssbyBlock(BasicBlock *s)
{
    for (Tac *t = s->tac_chain; t != NULL; t = t->next)
    {
        //当这句话是赋值语句时
        if (t->op_code >= Tac::ASSIGN && t->op_code <= Tac::LNOT)
            //addAssbyBlock(t->op0.var, s);
            ;
        else if (t->op_code == Tac::LOAD)
        {
            //addAssbyBlock(t->op0.var, s);
        }
        else if (t->op_code == Tac::CALL)
        {
            //addAssbyBlock(t->op0.var, s);
        }
    }
}

void ssa::placePhi()
{
    int cnttem = 0;
    for (auto val : allValue)
    {
        //TODO:判断临时变量
        // if (val->getType() == )
        //     continue;
        cnttem++;
        phiIns.clear();
        Added.clear();
        for (auto b : ssaIR->AssignbyBlock[val])
        {
            Added[b] = 1;
            blist.push(b);
        }

        while (blist.size())
        {
            BasicBlock *nowb = blist.front();
            blist.pop();
            for (auto d : ssaIR->DomainFrontier[nowb])
            {
                if (!phiIns[d])
                {
                    // Tac *t = new Tac(-1, Tac::Phi, 1);
                    if (val == nullptr)
                    {

                    }
                    // ins->addOperand(val);
                    // IR1->InsertInstr(ins);
                    // d->InstrList.insert(d->InstrList.begin(), IR1->InstList.size() - 1);
                    phiPos.insert(d);

                    phiIns[d] = 1;
                    if (!Added[d])
                    {
                        Added[d] = 1;
                        blist.push(d);
                    }
                }
            }
        }
    }
}

int hasUsedGlobal(Tac *tac, Symbol *stval)
{
    for (Tac *val = tac; val = val->next;val != nullptr)
    {
        // if (val == stval)
        //     return 1;
    }
    return 0;
}

void ssa::getssa()
{
    getAllValue(); 
    // for (auto gbval : allValue)
    // {
    //     if (gbval == NULL)
    //         continue;
    //     if (gbval->getType() == 1 && gbval->getScope() == "1")
    //     {
    //         // IntegerValue *tem = (IntegerValue *)gbval;
    //         if (tem->isConst)
    //             continue;
    //     }
    //     if (gbval->var_scope == "1" && gbval->getType() <= 2)
    //     {
    //         for (auto b : IR1->Blocks)
    //         {
    //             int iffind = 0;
    //             for (auto eb : b->domBlock)
    //             {
    //                 for (auto it = eb->InstrList.begin(); it != eb->InstrList.end(); it++)
    //                 {
    //                     Instruction *ins = IR1->InstList[(*it)];
    //                     int fl = hasUsedGlobal(ins, gbval);
    //                     if (fl)
    //                     {
    //                         if (iffind == 0)
    //                         {
    //                             Instruction *insld = new Instruction(-1, Instruction::Load, 1);
    //                             insld->setResult(gbval);
    //                             insld->addOperand(gbval);
    //                             IR1->InsertInstr(insld);
    //                             b->domBlock[0]->InstrList.push_front(IR1->InstList.size() - 1);

    //                             iffind = 1;
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    // for (auto i : FlowGraph)
    // {
    //     if (i->domBlock.size())
    //         build_domtree(i);
    // }

    // for (auto i : IR1->Blocks)
    // {
    //     if (i->domBlock.size())
    //     {
    //         for (auto j : i->domBlock)
    //             compute_boundary(j);
    //     }
    // }

    // //for (auto i : IR1->Blocks)
    // {
    //     if (i->domBlock.size())
    //     {
    //         for (auto param : i->FuncV->getParams())
    //         {
    //             addAssbyBlock(param, i->domBlock[0]);
    //         }
    //         for (auto j : i->domBlock)
    //         {
    //             setAssbyBlock(j);
    //         }
    //     }
    // }

}