/*****************************************************
 *  ARM Machine Description.
 *
 */

#ifndef __KNPC_ARMMD__
#define __KNPC_ARMMD__

#include "3rdparty/set.hpp"
#include "asm/mach_desc.hpp"
#include "asm/arm_frame_manager.hpp"
#include "util/define.hpp"

namespace knpc {
#define ARM_COMPONENTS_DEFINED
namespace assembly {
// for convinience
typedef util::Set<tac::Temp> LiveSet;

/**
 * ARM register.
 *
 * NOTE: we regard all general-purpose registers as caller-saved
 *
 */
struct ArmReg {
    enum {
        A1 = 0,
        A2,
        A3,
        A4,
        V1,
        V2,
        V3,
        V4,
        V5,
        V6,
        V7,
        FP,
        IP,
        SP,
        LR,
        PC,
        TOTAL_NUM // total number to registers
    };

    const char *name; // register name
    tac::Temp var;    // associated variable
    bool dirty;       // whether it is out of sychronized with the memory
    bool general;     // whether it is a generl-purpose register

    // two constructors for convenience
    ArmReg(const char *reg_name, bool is_general);
    ArmReg() {}
};

/**
 * ARM instruction.
 *
 * NOTE:
 *   1. it represents only the instructions used inside a basic block
 *   2. not all instructions are modeled (e.g. floting-point arithmetic instructions)
 * 
 */
struct ArmInstr : public Instr {
    enum OpCode {
        // assembler directives
        COMMENT,
        // instructions/pseudo instructions
        AND,
        OR,
        XOR,
        ADD,
        SUB,
        SUBS,
        MUL,
        DIV,
        INPLACE_MLS,
        NEG,
        J,
        BEQ,
        RET,
        LW,
        LI,
        SW,
        MV,
        NOT, //BNOT
        TEQZ,
        SEQ,
        CEQ,
        SNE,
        CNE,
        SLT,
        CLT,
        SLE,
        CLE,
        // SLTU,
        SGT,
        CGT,
        SGE,
        CGE,
        CALL,
        MOVW,
        MOVT,
        PUSH,
        POP,
        // You could add other instructions/pseudo instructions here
    } op_code; // operation code

    ArmReg *r0, *r1, *r2; // 3 register operands
    short reglist;
    int i;                  // offset or immediate number
    std::string l;          // target label. for LA, B, BEQZ or JAL
    std::string comment;    // comment in this line

    ArmInstr *next; // next instruction

    // "cancelled" field is inherited from assembly::Instr.
};

/**
 * ARM machine description.
 *
 * The main function of ArmDesc is to translate a "Piece" into assembly code.
 */
class ArmDesc : public MachineDesc {
  public:
    // constructor
    ArmDesc();
    // gets the offset counter for ARM
    virtual OffsetCounter *getOffsetCounter(void);
    // translates the given "tac::Piece" into ARM assembly code
    virtual void emitPieces(scope::GlobalScope *, tac::Piece *,
                            std::ostream &os);

  private:
    // where to output the assembly code
    std::ostream *_result;
    // riscv offset counter
    OffsetCounter *_counter;
    // auxilliary field for addInstr
    ArmInstr *_tail;
    // stack-frame manager for `register spilling`
    ArmStackFrameManager *_frame;
    // label counter for allocating new labels
    int _label_counter;
    
    // allocates a new label
    const char *getNewLabel(void);
    // translates the tac_chain of a basic block into the instr_chain
    ArmInstr *prepareSingleChain(tac::BasicBlock *, tac::FlowGraph *);

    // translates a TAC into assembly instructions
    void emitTac(tac::Tac *);
    // translates a LoadImm4 TAC into assembly instructions
    void emitLoadImm4Tac(tac::Tac *);
    // translates a LoadSymbol TAC into assembly instructions
    void emitLoadSymbolTac(tac::Tac *);
    // translates a Load TAC into assembly instructions
    void emitLoadTac(tac::Tac *);
    // translates a Store TAC into assembly instructions
    void emitStoreTac(tac::Tac *);
    // translates a Unary TAC into assembly instructions
    void emitUnaryTac(ArmInstr::OpCode, tac::Tac *);
    // translates a Binary TAC into assembly instructions
    void emitBinaryTac(ArmInstr::OpCode, tac::Tac *);
    // translates a Push TAC into assembly instructions
    void emitPushTac(tac::Tac *);
    // translates a Call TAC into assembly instructions
    void emitCallTac(tac::Tac *);
    
    void emitAllocTac(tac::Tac *);

    // outputs an instruction
    void emit(std::string, const char *, const char *);
    // outputs a function
    void emitFuncty(tac::Functy);
    // prints the leading code of a function
    void emitProlog(tac::Label, int);
    // prints the assembly code of a single trace
    void emitTrace(tac::BasicBlock *, tac::FlowGraph *);
    // prints a single ARM instruction
    void emitInstr(ArmInstr *);
    // appends a new instruction to "_tail"
    void addInstr(ArmInstr::OpCode, ArmReg *, ArmReg *, ArmReg *, int,
                  std::string, std::string);
    void addRegListInstr(ArmInstr::OpCode, short reglist, std::string);


    /*** sketch for peephole optimizer (inside a basic block) ***/
    void simplePeephole(ArmInstr *);


    /*** the register allocator ***/
    ArmReg *_reg[ArmReg::TOTAL_NUM]; // registers of a machine
    int _lastUsedReg;                    // which register was used last?

    // acquires a register to read the value of a variable
    int getRegForRead(tac::Temp, int, LiveSet *);
    // acquires a register to write the value of a variable
    int getRegForWrite(tac::Temp, int, int, LiveSet *);
    // spills the content of a register into memory
    void spillReg(int, LiveSet *);
    // spills all dirty registers into memory (for control-flow change)
    void spillDirtyRegs(LiveSet *);
    // looks up a register holding the specified variable
    int lookupReg(tac::Temp);
    // selects a register to spill into memory
    int selectRegToSpill(int, int, LiveSet *);
};

} // namespace assembly
} // namespace knpc

#endif // __KNPC_ARMMD__
