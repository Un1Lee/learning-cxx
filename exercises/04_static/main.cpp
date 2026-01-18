#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？

//普通函数默认是 外部链接（external linkage）：可以在其他 .cpp 文件中通过声明（extern）调用；
//static 函数是 内部链接（internal linkage）：仅能在定义该函数的当前文件中被调用，其他文件无法访问（即使声明也不行）。
static int func(int param) {
    static int static_ = param;
    // // 编译器自动插入的“初始化判断逻辑”
    // if (is_first_init) {
    //     static_local = 40; // 第一次才执行初始化
    //     is_first_init = false; // 标记为已初始化
    // }
    // std::cout << "static_ = " << static_ << std::endl;
    return static_++;
    // return static_++ 是后置自增，先返回当前值，再自增
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect");
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}
