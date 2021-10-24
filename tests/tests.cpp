#include <gtest/gtest.h>

#define private public

#include <class_s.h>

//TEST(ADD, ADD_empty){
//    param_stack a(4);
//    a.add();
//    ASSERT_EQ(a[0].a, 1);
//    ASSERT_EQ(a[0].b, 1);
//    ASSERT_DOUBLE_EQ(a[0].c, 1.1);
//    ASSERT_EQ(a[0].d, "1");
//}

TEST(ADD, ADD_params) {
    param_stack a(4);
    a.add(1, 1, 1.1, "1");
    ASSERT_EQ(a[0].a, 1);
    ASSERT_EQ(a[0].b, 1);
    ASSERT_DOUBLE_EQ(a[0].c, 1.1);
    ASSERT_EQ(a[0].d, "1");
}

TEST(ADD, ADD_copy) {
    param_stack a(4);
    a.add(1, 1, 1.1, "1");
    a.add(a[0]);
    ASSERT_EQ(a[1].a, 1);
    ASSERT_EQ(a[1].b, 1);
    ASSERT_DOUBLE_EQ(a[1].c, 1.1);
    ASSERT_EQ(a[1].d, "1");
}

TEST(ADD, ADD_overflow) {
    param_stack a(4);
    a.add(1, 1, 1.1, "1");
    a.add(1, 1, 1.1, "1");
    a.add(1, 1, 1.1, "1");
    a.add(1, 1, 1.1, "1");
    ASSERT_ANY_THROW(a.add(1, 1, 1.1, "1"));
}

TEST(DEL, DEL_last) {
    param_stack a(4);
    a.add(1, 1, 1.1, "1");
    a.add(2, 2, 2.2, "2");
    a.add(3, 3, 3.3, "3");
    int prev_size = a.cur_size;
    a.del(2);
    ASSERT_NE(prev_size, a.cur_size);
}

TEST(DEL, DEL_nlast) {
    param_stack a(4);
    a.add(1, 1, 1.1, "1");
    a.add(2, 2, 2.2, "2");
    a.add(3, 3, 3.3, "3");\
    data data(a[2]);
    int prev_size = a.cur_size;
    a.del(0);
    ASSERT_NE(prev_size, a.cur_size);
    ASSERT_EQ(data.a, a[0].a);
    ASSERT_EQ(data.b, a[0].b);
    ASSERT_EQ(data.c, a[0].c);
    ASSERT_EQ(data.d, a[0].d);
}

TEST(DEL, DEL_badindex) {
    param_stack a(4);
    a.add(1, 1, 1.1, "1");
    a.add(2, 2, 2.2, "2");
    a.add(3, 3, 3.3, "3");
    ASSERT_ANY_THROW(a.del(6));
}

