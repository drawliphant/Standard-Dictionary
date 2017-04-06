cmake_minimum_required(VERSION 3.7)
project(GenericDictionary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp .idea/ KeyValue.cpp KeyValue.h Dictionary.cpp Dictionary.h)
add_executable(GenericDictionary ${SOURCE_FILES})

set(TEST_FILES
        KeyValue.cpp KeyValue.h Dictionary.cpp Dictionary.h
        Testing/testingMain.cpp
        Testing/KeyValueTester.cpp Testing/KeyValueTester.h
        Testing/DictionaryTester.cpp Testing/DictionaryTester.h)


add_executable(Test ${TEST_FILES})