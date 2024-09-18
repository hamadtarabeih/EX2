#include "Complex.hpp"
#include "Tree.hpp"
#include "doctest.h"
#include "Tree.cpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

// Helper function to convert Complex to string with specified precision
std::string to_string_with_precision(const Complex &value, int precision = 1)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value.real;
    return out.str();
}

TEST_CASE("Tree Traversals")
{
    SUBCASE("PreOrder_IntegerTree")
    {
        Tree<int> tree;
        tree.add_root(1);
        tree.add_sub_node(1, 2);
        tree.add_sub_node(1, 3);
        tree.add_sub_node(2, 4);
        tree.add_sub_node(2, 5);
        tree.add_sub_node(3, 6);
        tree.add_sub_node(3, 7);

        std::string expected = "1 2 4 5 3 6 7 ";
        std::string actual = "";

        for (auto it = tree.begin_pre_order(); it->hasNext();)
        {
            actual += std::to_string(it->next()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("InOrder_IntegerTree")
    {
        Tree<int> tree;
        tree.add_root(1);
        tree.add_sub_node(1, 2);
        tree.add_sub_node(1, 3);
        tree.add_sub_node(2, 4);
        tree.add_sub_node(2, 5);
        tree.add_sub_node(3, 6);
        tree.add_sub_node(3, 7);

        std::string expected = "4 2 5 1 6 3 7 ";
        std::string actual = "";

        for (auto it = tree.begin_in_order(); it->hasNext();)
        {
            actual += std::to_string(it->next()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("PostOrder_IntegerTree")
    {
        Tree<int> tree;
        tree.add_root(1);
        tree.add_sub_node(1, 2);
        tree.add_sub_node(1, 3);
        tree.add_sub_node(2, 4);
        tree.add_sub_node(2, 5);
        tree.add_sub_node(3, 6);
        tree.add_sub_node(3, 7);

        std::string expected = "4 5 2 6 7 3 1 ";
        std::string actual = "";

        for (auto it = tree.begin_post_order(); it->hasNext();)
        {
            actual += std::to_string(it->next()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("PreOrder_ComplexTree")
    {
        Tree<Complex> tree;
        tree.add_root(Complex(1.0, 1.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(2.0, 2.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(3.0, 3.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(4.0, 4.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(5.0, 5.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(6.0, 6.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(7.0, 7.0));

        std::string expected = "1.0 2.0 4.0 5.0 3.0 6.0 7.0 ";
        std::string actual = "";

        for (auto it = tree.begin_pre_order(); it->hasNext();)
        {
            actual += to_string_with_precision(it->next()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("InOrder_ComplexTree")
    {
        Tree<Complex> tree;
        tree.add_root(Complex(1.0, 1.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(2.0, 2.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(3.0, 3.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(4.0, 4.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(5.0, 5.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(6.0, 6.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(7.0, 7.0));

        std::string expected = "4.0 2.0 5.0 1.0 6.0 3.0 7.0 ";
        std::string actual = "";

        for (auto it = tree.begin_in_order(); it->hasNext();)
        {
            actual += to_string_with_precision(it->next()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("PostOrder_ComplexTree")
    {
        Tree<Complex> tree;
        tree.add_root(Complex(1.0, 1.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(2.0, 2.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(3.0, 3.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(4.0, 4.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(5.0, 5.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(6.0, 6.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(7.0, 7.0));

        std::string expected = "4.0 5.0 2.0 6.0 7.0 3.0 1.0 ";
        std::string actual = "";

        for (auto it = tree.begin_post_order(); it->hasNext();)
        {
            actual += to_string_with_precision(it->next()) + " ";
        }

        CHECK(expected == actual);
    }
}

TEST_CASE("Tree Structure")
{
    SUBCASE("Add_SubNode")
    {
        Tree<int> tree;
        tree.add_root(1);
        tree.add_sub_node(1, 2);
        tree.add_sub_node(1, 3);
        tree.add_sub_node(2, 4);
        tree.add_sub_node(2, 5);
        tree.add_sub_node(3, 6);
        tree.add_sub_node(3, 7);

        std::string expected_pre_order = "1 2 4 5 3 6 7 ";
        std::string actual_pre_order = "";

        for (auto it = tree.begin_pre_order(); it->hasNext();)
        {
            actual_pre_order += std::to_string(it->next()) + " ";
        }

        CHECK(expected_pre_order == actual_pre_order);
    }

    SUBCASE("Add_SubNode_Complex")
    {
        Tree<Complex> tree;
        tree.add_root(Complex(1.0, 1.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(2.0, 2.0));
        tree.add_sub_node(Complex(1.0, 1.0), Complex(3.0, 3.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(4.0, 4.0));
        tree.add_sub_node(Complex(2.0, 2.0), Complex(5.0, 5.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(6.0, 6.0));
        tree.add_sub_node(Complex(3.0, 3.0), Complex(7.0, 7.0));

        std::string expected_pre_order = "1.0 2.0 4.0 5.0 3.0 6.0 7.0 ";
        std::string actual_pre_order = "";

        for (auto it = tree.begin_pre_order(); it->hasNext();)
        {
            actual_pre_order += to_string_with_precision(it->next()) + " ";
        }

        CHECK(expected_pre_order == actual_pre_order);
    }
}

// Additional Tests for Complex Class
TEST_CASE("Complex Class Functions")
{
    SUBCASE("Complex Addition")
    {
        Complex c1(1.0, 1.0);
        Complex c2(2.0, 2.0);
        Complex result = c1 + c2;

        CHECK(result.real == 3.0);
        CHECK(result.imag == 3.0);
    }

    SUBCASE("Complex Equality")
    {
        Complex c1(1.0, 1.0);
        Complex c2(1.0, 1.0);
        Complex c3(2.0, 2.0);

        CHECK(c1 == c2);
        CHECK(!(c1 == c3));
    }

    SUBCASE("Complex Output Stream")
    {
        Complex c(1.234567, 0.0);
        std::ostringstream out;
        out << c;

        CHECK(out.str() == "[1.23457, 0i]");
    }
}
