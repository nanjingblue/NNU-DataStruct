include_directories(Head)

add_executable(stack01 stack01.cpp Head/SeqStack.h Source/SeqStack.cpp)
add_executable(stack02 stack02.cpp Head/LinkStack.h)
add_executable(StackApp01 StackApp01.cpp Head/SeqStack.h)
add_executable(StackApp02 StackApp02.cpp Head/SeqStack.h)
add_executable(StackApp03 StackApp03.cpp Head/SeqStack.h)
add_executable(StackExercise01 StackExercise01.cpp Head/LinkStack.h)
add_executable(StackExercise02 StackExercise02.cpp Head/LinkStack.h)
add_executable(StackExercise03 StackExercise03.cpp Head/LinkStack.h)
add_executable(StackExercise04 StackExercise04.cpp Head/LinkStack.h)
add_executable(StackExercise05 StackExercise05.cpp Head/LinkStack.h)
add_executable(Queue01 Queue01.cpp Head/SeqQueue.h)
add_executable(Queue02 Queue02.cpp Head/LinkQueue.h)
add_executable(QueueApp01 QueueApp01.cpp Head/LinkStack.h Head/LinkQueue.h)