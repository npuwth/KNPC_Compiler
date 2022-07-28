#include "../util/config.hpp"
#include "../util/options.hpp"
#include "../frontend/tac/tac.hpp"
#include "../frontend/tac/flow_graph.hpp"
#include "../frontend/symb/symbol.hpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace knpc;
using namespace knpc::tac;
using namespace knpc::symb;
/*********************************SSA***************************************/
struct DomTreenode
{
    Functy *func = nullptr;
    std::vector<DomTreenode *> son;   // 支配树子结点
    BasicBlock *block = nullptr; // 这个节点对应的block
    DomTreenode *idom = nullptr; // 这个节点的直接支配节点
};
class ssa
{
    private:
        int dfscnt = 0;
        std::map<DomTreenode *, int> semi;                       //半支配结点
        std::map<DomTreenode *, DomTreenode *> parent;           //父结点
        std::map<DomTreenode *, std::vector<DomTreenode *>> bucket;   
        std::vector<DomTreenode *> vertex;                       //顶点
        std::map<DomTreenode *, DomTreenode *> ancestor;         //祖先结点
        std::map<DomTreenode *, DomTreenode *> label;            
        std::vector<DomTreenode *> DomRoot;
        std::map<BasicBlock *, DomTreenode *> block2dom;
        std::map<Symbol *, std::vector<BasicBlock *>> AssignbyBlock;   //对val赋值过的block *
        std::map<BasicBlock *, std::set<BasicBlock *>> DomainFrontier; //支配边界           *
        std::map<BasicBlock *, bool> phiIns;
        std::map<BasicBlock *, bool> Added;
        std::queue<BasicBlock *> blist;
        std::set<BasicBlock *> phiPos;
        std::set<Symbol *> allValue;

    public:
        void init();                            //初始化
        void dfsLT(DomTreenode *dang);          //DFS
        void compress(DomTreenode *v);          //路径压缩
        DomTreenode *eval(DomTreenode *v);      //并查集
        void build_domtree(BasicBlock *s);      //构建支配树
        void compute_boundary(BasicBlock *b);   //计算支配树的边界
        void getAllValue();                     //计算所有的值
        void addAssbyBlock(Symbol *val, BasicBlock *b);  //加入给变量赋值的块
        void setAssbyBlock(BasicBlock *s);               //设置给变量赋值的块
        void placePhi();                                 //设置phi函数
        void getssa();                                      //生成ssa
};
