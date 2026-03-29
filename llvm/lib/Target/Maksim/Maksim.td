include "llvm/Target/Target.td"
include "MaksimRegisterInfo.td"
include "MaksimInstrInfo.td"
include "MaksimCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def MaksimInstrInfo : InstrInfo;
def Maksim : Target {
  let InstructionSet = MaksimInstrInfo;
}
