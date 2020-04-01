PROCESSOR_DERIVATIVE = 'STM32L476xx'
import os
env = Environment(tools = ['gcc', 'gnulink'], ENV = os.environ)

env['AR'] = 'arm-none-eabi-ar'
env['AS'] = 'arm-none-eabi-as'
env['CC'] = 'arm-none-eabi-gcc'
env['CXX'] = 'arm-none-eabi-g++'
env['LINK'] = 'arm-none-eabi-g++'                # predefined is 'arm-none-eabi-gcc'
env['RANLIB'] = 'arm-none-eabi-ranlib'
env['OBJCOPY'] = 'arm-none-eabi-objcopy'
env['PROGSUFFIX'] = '.elf'

# C-defines
env.Append( CPPDEFINES = [
    PROCESSOR_DERIVATIVE,
    'USE_FULL_ASSERT',
])

# Include locations
env.Append( CPPPATH = [
    'Drivers/CMSIS/Core/Include',
    'Drivers/CMSIS/Device/',
    'Drivers/CMSIS/Include',
    'Drivers/STM32L4xx_HAL_Driver/Inc',
    'inc',
])

# Compiler flags
env.Append( CCFLAGS = [
    '-mthumb',
    '-mcpu=cortex-m4',
    '-mfloat-abi=hard',
    '-mfpu=fpv4-sp-d16',
    '-std=gnu11',
    #'-Ofast',
    '-ffunction-sections',
    '-fdata-sections',
    '-g',
    '-Wall',
    '-specs=nano.specs',
])

# Linker flags
env.Append( LINKFLAGS = [
    '-mthumb',
    '-mcpu=cortex-m4',
    '-mfloat-abi=hard',
    '-mfpu=fpv4-sp-d16',
    '-specs=nosys.specs',
    '-static',
    '-Wl,-cref,-u,Reset_Handler',
    '-Wl,-Map=main.map',
    '-Wl,--gc-sections',
    '-Wl,--defsym=malloc_getpagesize_P=0x80',
    '-Wl,--start-group',
    '-lc',
    '-lm',
    '-Wl,--end-group',
    '-specs=nano.specs',
    '-TSTM32L476RGTx_FLASH.ld',
]) 

startup_file_name = 'startup_' + PROCESSOR_DERIVATIVE.lower() + '.s'
# Source locations
prg = env.Program(
    target = 'main',
    source = [
            'main.c',
            'src/stm32l4xx_it.c',
            startup_file_name,
            'src/system_stm32l4xx.c',
    ]
)

# binary file builder
def arm_generator(source, target, env, for_signature):
    return '$OBJCOPY -O binary %s %s'%(source[0], target[0])
env.Append(BUILDERS = {
    'Objcopy': Builder(
        generator=arm_generator,
        suffix='.bin',
        src_suffix='.elf'
    )
})
 
env.Objcopy(prg)