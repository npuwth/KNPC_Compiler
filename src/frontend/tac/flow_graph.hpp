/*****************************************************
 *  Definition of "BasicBlock" and "FlowGraph".
 *  The flow graph and dataflow analysis part are almost finished,
 *  if you want to learn dataflow analysis with codes, please refer to codes here.
 *
 *  Of course, if you add some new Tacs,
 *  you are supposed to update the codes at line 38 and line 176 in tac/dataflow.cpp
 */

#ifndef __KNPC_FLOWGRAPH__
#define __KNPC_FLOWGRAPH__

#include "3rdparty/set.hpp"
#include "3rdparty/vector.hpp"
#include "asm/mach_desc.hpp"
#include "util/define.hpp"

#include <iostream>

namespace knpc
{

#define KNPC_FLOWGRAPH_DEFINED
    namespace tac
    {

        /**
         * Basic Block.
         * 基本块是最小的不包括跳转的代码块
         */
        struct BasicBlock
        {
            /*********************************** 基本定义 **************************************/
            int bb_num; // 基本块编号
            enum
            {
                BY_JUMP,
                BY_JZERO,
                BY_RETURN
            } end_kind;     // 终止语句

            int in_degree;  // 入度
            Temp var;       // 对于jzero语句块,var表示条件变量
                            // 对于return语句块,var表示返回值

            int next[2];        // 跳转块的编号
                                // for END-BY-JZERO blocks, next[0] is the successor
                                //  of condition = 0, while next[1] is the successor
                                //  of condition = 1;
                                // for END-BY-JUMP blocks, next[0]=next[1]=successor

            bool cancelled; // internal flag for FlowGraph
            int mark;       // internal flag for MachDesc

            Tac *tac_chain; // the associated TAC sequence fragment

            assembly::Instr *instr_chain; // for ASM code generation: the associated assembly code sequence
            const char *entry_label;      // for ASM code generation: the associated entry label in assembly code


            /************************************ 活跃变量分析 ***********************************/
            util::Set<Temp> *Def;     // the DEF set: ALL variables defined in this block
            util::Set<Temp> *LiveUse; // the LiveUSE set: all used-before-defined variables
            util::Set<Temp> *LiveIn;  // the LiveIn set: all variables alive at the entry
            util::Set<Temp> *LiveOut; // the LiveOut set: all variables alive at the exit

            // constructor
            BasicBlock();
            // computes the DEF set and LiveUse set
            void computeDefAndLiveUse(void); // in tac/dataflow.cpp
            // computes the LiveOut set of every TAC inside (see also:
            // 控制流图，活跃变量分析
            void analyzeLiveness(void); 
            // 打印基本块
            void dump(std::ostream &);

            void updateLU(Temp);
            void updateDEF(Temp);
            /************************************ 支配树，SSA ***********************************/
            //后继基本块
            std::vector<BasicBlock *> succBlock;
            //前驱基本块
            std::vector<BasicBlock *> pioneerBlock;
            //属于的函数体
            BasicBlock *parent_ = nullptr;
            //函数所控制的基本块
            std::vector<BasicBlock *> domBlock;
            //对应符号表中的函数
            Functy *Func = nullptr;

            std::list<int> InstrList;
        };

        /**
         * Control-flow Graph (CFG).
         *
         * Control-flow graph is a set of basic blocks
         * (edges are the ``successor'' relationship).
         */
        class FlowGraph
        {
        private:
            util::Vector<BasicBlock *> _bbs; // basic blocks
            int _n;                          // number of basic blocks

            FlowGraph()
            { /* don't invoke me */
            }

        public:
            typedef util::Vector<BasicBlock *>::iterator iterator;
            typedef util::Vector<BasicBlock *>::reverse_iterator reverse_iterator;

            // 构建函数的控制流图
            static FlowGraph *makeGraph(Functy);
            // 优化控制流图
            void simplify(void);
            // 得到指定的一个基本块
            BasicBlock *getBlock(int);
            // 得到控制流图的大小
            size_t size(void);
            // 指向第一个基本块
            iterator begin(void);
            // 指向最后一个基本块
            iterator end(void);
            // 反向迭代器的开始
            reverse_iterator rbegin(void);
            // 反向迭代器的结束
            reverse_iterator rend(void);
            // 计算每个基本块的输入点和输出点
            void analyzeLiveness(void); // in tac/dataflow.cpp
            // 打印控制流图
            void dump(std::ostream &);
        };

    } // namespace tac

    // an auxilliary function for printing variable set
    std::ostream &operator<<(std::ostream &, util::Set<tac::Temp> *);
} // namespace knpc

#endif // __KNPC_FLOWGRAPH__
