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
    param_stack a;
    a.add(1, 1, 1.1, "1");
    ASSERT_EQ(a[0].a, 1);
    ASSERT_EQ(a[0].b, 1);
    ASSERT_DOUBLE_EQ(a[0].c, 1.1);
    ASSERT_EQ(a[0].d, "1");
}

TEST(ADD, ADD_copy) {
    param_stack a;
    a.add(1, 1, 1.1, "1");
    a.add(a[0]);
    ASSERT_EQ(a[1].a, 1);
    ASSERT_EQ(a[1].b, 1);
    ASSERT_DOUBLE_EQ(a[1].c, 1.1);
    ASSERT_EQ(a[1].d, "1");
}

TEST(ADD, ADD_overflow) {
    param_stack a;
    a.add(1, 1, 1.1, "1");
    a.add(1, 1, 1.1, "1");
    a.add(1, 1, 1.1, "1");
    a.add(1, 1, 1.1, "1");
    a.add(1, 1, 1.1, "1");
    ASSERT_ANY_THROW(a.add(1, 1, 1.1, "1"));
}
//
//TEST(OPERS, OPERS_enter) {
//    param_stack a;
//    ASSERT_ANY_THROW(std::cin >> a;);
//}

TEST(OPERS, OPERS_indexing){
    param_stack a;
    a.add(2, 2, 2.3, "2");
    ASSERT_EQ(a[0].a, a.stack[0].a);
    ASSERT_EQ(a[0].b, a.stack[0].b);
    ASSERT_DOUBLE_EQ(a[0].c, a.stack[0].c);
    ASSERT_EQ(a[0].d, a.stack[0].d);
}

TEST(OPERS, OPERS_plus) {
    param_stack a;
    a.add(1, 1, 2.2, "2");
    a.add(2, 2, 2.2, "2");
    a.add(3, 3, 3.3, "3");
    a.add(4, 4, 4.4, "4");
    param_stack b;
    b.add(1, 1, 2.2, "2");
    b.add(2, 2, 2.2, "2");
    b.add(3, 3, 3.3, "3");
    b.add(4, 4, 4.4, "4");
    param_stack c = a + b;
    ASSERT_EQ(a[0].a, c[0].a);
    ASSERT_EQ(a[0].b, c[0].b);
    ASSERT_DOUBLE_EQ(a[0].c, c[0].c);
    ASSERT_EQ(a[0].d, c[0].d);
    ASSERT_EQ(b[0].a, c[4].a);
    ASSERT_EQ(b[0].b, c[4].b);
    ASSERT_DOUBLE_EQ(b[0].c, c[4].c);
    ASSERT_EQ(b[0].d, c[4].d);
}

TEST(OPERS, OPERS_plusplus){
    param_stack a;
    ++a;
    ASSERT_EQ(a[0].a, 0);
    ASSERT_EQ(a[0].a, 0);
    ASSERT_DOUBLE_EQ(a[0].c, 0.0);
    ASSERT_EQ(a[0].a, 0);
    param_stack b = a++;
    ASSERT_ANY_THROW(b[1]);
}

TEST(OPERS, OPERS_minus){
    param_stack a;
    a.add(1, 1, 1.1, "1");
    -a;
    ASSERT_EQ(a[0].a, -1);
    ASSERT_EQ(a[0].b, -1);
    ASSERT_DOUBLE_EQ(a[0].c, -1.1);
}

TEST(OPERS, OPERS_eqplus_overflow){
    param_stack a;
    a.add(1, 1, 2.2, "2");
    a.add(2, 2, 2.2, "2");
    a.add(3, 3, 3.3, "3");
    a.add(4, 4, 4.4, "4");
    param_stack b;
    b.add(1, 1, 2.2, "2");
    b.add(2, 2, 2.2, "2");
    b.add(3, 3, 3.3, "3");
    b.add(4, 4, 4.4, "4");
    ASSERT_ANY_THROW(a+=b);
}

TEST(OPERS, OPERS_eqplus){
    param_stack a;
    int size = a.size;
    a.add(1, 1, 2.2, "2");
    a.add(2, 2, 2.2, "2");
    param_stack b;
    b.add(1, 1, 2.2, "2");
    b.add(2, 2, 2.2, "2");
    a+=b;
    ASSERT_EQ(a[2].a, b[0].a);
    ASSERT_EQ(a[2].b, b[0].b);
    ASSERT_DOUBLE_EQ(a[2].c, b[0].c);
    ASSERT_EQ(a[2].d, b[0].d);
    ASSERT_EQ(size, a.size);
}

TEST(DEL, DEL_last) {
    param_stack a;
    a.add(1, 1, 1.1, "1");
    a.add(2, 2, 2.2, "2");
    a.add(3, 3, 3.3, "3");
    int prev_size = a.cur_size;
    a.del(2);
    ASSERT_NE(prev_size, a.cur_size);
}

TEST(DEL, DEL_nlast) {
    param_stack a;
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
    param_stack a;
    a.add(1, 1, 1.1, "1");
    a.add(2, 2, 2.2, "2");
    a.add(3, 3, 3.3, "3");
    ASSERT_ANY_THROW(a.del(6));
}

