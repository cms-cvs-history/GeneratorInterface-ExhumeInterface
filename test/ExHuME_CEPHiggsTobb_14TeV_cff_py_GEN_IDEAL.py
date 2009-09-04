# Auto generated configuration file
# using: 
# Revision: 1.110 
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: Configuration/GenProduction/python/ExHuME_CEPHiggsTobb_14TeV_cff.py -s GEN --conditions FrontierConditions_GlobalTag,IDEAL_30X::All --datatier GEN --eventcontent RAWSIM -n 1000 --no_exec
import FWCore.ParameterSet.Config as cms

process = cms.Process('GEN')

# import of standard configurations
process.load('Configuration/StandardSequences/Services_cff')
process.load('FWCore/MessageService/MessageLogger_cfi')
process.load('Configuration/StandardSequences/MixingNoPileUp_cff')
process.load('Configuration/StandardSequences/GeometryIdeal_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/Generator_cff')
process.load('Configuration/StandardSequences/VtxSmearedEarly10TeVCollision_cff')
process.load('Configuration/StandardSequences/EndOfProcess_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load('Configuration/EventContent/EventContent_cff')

process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.2 $'),
    annotation = cms.untracked.string('ExHuME CEP of H->bb at 14TeV'),
    name = cms.untracked.string('$Source: /cvs_server/repositories/CMSSW/CMSSW/GeneratorInterface/ExhumeInterface/test/ExHuME_CEPHiggsTobb_14TeV_cff_py_GEN_IDEAL.py,v $')
)
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)
process.options = cms.untracked.PSet(
    Rethrow = cms.untracked.vstring('ProductNotFound')
)

process.source = cms.Source("EmptySource")

process.generator = cms.EDFilter("ExhumeGeneratorFilter",
    PythiaParameters = cms.PSet(
       parameterSets = cms.vstring()
    ),
    ExhumeParameters = cms.PSet(
       HiggsVev = cms.double(246.0),
       HiggsMass = cms.double(120.0),
       MuonMass = cms.double(0.1057),
       LambdaQCD = cms.double(80.0),
       ZMass = cms.double(91.187),
       TauMass = cms.double(1.77),
       PDF = cms.double(20250),
       BottomMass = cms.double(4.6),
       AlphaEw = cms.double(0.0072974),
       WMass = cms.double(80.33),
       StrangeMass = cms.double(0.19),
       Survive = cms.double(0.03),
       TopMass = cms.double(175.0),
       Rg = cms.double(1.2),
       CharmMass = cms.double(1.42),
       MinQt2 = cms.double(0.64),
       B = cms.double(4.0)
    ),
    comEnergy = cms.double(14000.),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    maxEventsToPrint = cms.untracked.int32(2),
    pythiaPylistVerbosity = cms.untracked.int32(1),
    ExhumeProcess = cms.PSet(
        ThetaMin = cms.double(0.95),
        MassRangeLow = cms.double(115.0),
        MassRangeHigh = cms.double(125.0),
        ProcessType = cms.string('Higgs'),
        HiggsDecay = cms.int32(5),
    )
)

# Output definition
process.output = cms.OutputModule("PoolOutputModule",
    outputCommands = process.RAWSIMEventContent.outputCommands,
    fileName = cms.untracked.string('ExHuME_CEPHiggsTobb_14TeV_cff_py_GEN.root'),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN'),
        filterName = cms.untracked.string('')
    ),
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    )
)

# Additional output definition

# Other statements
process.GlobalTag.globaltag = 'MC_31X_V5::All'

# Path and EndPath definitions
process.generation_step = cms.Path(process.generator*process.pgen)
process.endjob_step = cms.Path(process.endOfProcess)
process.out_step = cms.EndPath(process.output)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.endjob_step,process.out_step)
