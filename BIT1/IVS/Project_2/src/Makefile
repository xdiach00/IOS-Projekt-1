#/**************************************************************
# * Authors:   Diachenko Mikhail <xdiach00@stud.fit.vutbr.cz>
# *            Isaichanka Herman <xisaic00@stud.fit.vutbr.cz>
# *            Kopecký Jan <xkopec59@stud.fit.vutbr.cz>
# *            Santarius Ivo <xsanta09@stud.fit.vutbr.cz>
# **************************************************************/

# Windows dependencies
# Install + add /bin path to PATH variable
# GNU make for Windows http://gnuwin32.sourceforge.net/packages/make.htm
# GNU zip for Windows http://gnuwin32.sourceforge.net/packages/zip.htm
# Doxygen for Windows https://www.doxygen.nl/download.html

ROOT_DIR="${CURDIR}"
VISUAL_STUDIO_PATH="C:\Program Files\Microsoft Visual Studio\2022\Community"
MSBUILD="Msbuild\Current\Bin\MSBuild.exe"

SLN_PROJECT="Calculat.sln"

TEST_FILE="tests/tests.cpp"
TEST_OUTPUT=tests.exe

EXE_PATH=x64\Debug\Calculat.exe

PROFILING_PATH="profiling/profiling.cpp"
PROFILING_OUTPUT=profiling.exe
PROFILING_NUMBERS_TXT="profiling/test.txt"

DOXYGEN_PATH="C:\Program Files\doxygen\bin\doxygen.exe"

DIR_PATH_OF_REPOSITORY="ivs-proj2"
FILE_PATH_OF_SETUP_FILE=$(DIR_PATH_OF_REPOSITORY)/src/install/.
DIR_PATH_OF_DOCUMMENTATION=$(DIR_PATH_OF_REPOSITORY)/src/doxygen_output/.
ZIP_FILE_NAME="xkopec59_xdiach00_xisaic00_xsanta09"

.PHONY: all build pack clean test_compile test doc run profile

all: profile test_compile
	cd $(VISUAL_STUDIO_PATH) && $(MSBUILD) $(ROOT_DIR)/$(SLN_PROJECT)

pack: doc
	cd .. && cd .. && mkdir $(ZIP_FILE_NAME) && mkdir $(ZIP_FILE_NAME)/doc && cp -r $(DIR_PATH_OF_DOCUMMENTATION) $(ZIP_FILE_NAME)/doc && mkdir $(ZIP_FILE_NAME)/install && cp -r $(FILE_PATH_OF_SETUP_FILE) $(ZIP_FILE_NAME)/install && mkdir $(ZIP_FILE_NAME)/repo && cd ivs-proj2/src && make clean && cd .. && cd .. && cp -r $(DIR_PATH_OF_REPOSITORY)/. $(ZIP_FILE_NAME)/repo && zip -r $(ZIP_FILE_NAME).zip $(ZIP_FILE_NAME) && rm -rf $(ZIP_FILE_NAME)

clean:
	rm -f *.exe *.o *.out
	rm -rf x64 doxygen_output

test_compile:
	g++ $(TEST_FILE) -o $(TEST_OUTPUT)

test: test_compile
	$(TEST_OUTPUT)

doc: Doxyfile
	$(DOXYGEN_PATH) $<
run:
	$(EXE_PATH)
profile:
	g++ $(PROFILING_PATH) -o $(PROFILING_OUTPUT)
