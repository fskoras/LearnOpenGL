#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/common.o \
	${OBJECTDIR}/glad.o \
	${OBJECTDIR}/input.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/model.o \
	${OBJECTDIR}/shader.o \
	${OBJECTDIR}/system.o \
	${OBJECTDIR}/window.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Llib -lglfw3 -lopengl32 -lgdi32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/learnopengl.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/learnopengl.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	gcc -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/learnopengl ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/common.o: common.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/common.o common.c

${OBJECTDIR}/glad.o: glad.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/glad.o glad.c

${OBJECTDIR}/input.o: input.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/input.o input.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/model.o: model.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/model.o model.c

${OBJECTDIR}/shader.o: shader.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/shader.o shader.c

${OBJECTDIR}/system.o: system.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/system.o system.c

${OBJECTDIR}/window.o: window.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -D_USE_STDDEF_ -Iincludes -Ilib/cglm -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/window.o window.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
