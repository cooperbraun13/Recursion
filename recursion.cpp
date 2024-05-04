#include<iostream>
#include<cassert>

int recursive_function(int factor_a, int factor_b) {
    // std::cout << factor_a << " | " << factor_b << std::endl;
    if(factor_a < 0 && factor_b < 0) {
        return recursive_function(-factor_a, -factor_b);
    }
    if(factor_a < 0 && factor_b > 0) {
        return -recursive_function(-factor_a, factor_b);
    }
    if(factor_a > 0 && factor_b < 0) {
        return -recursive_function(factor_a, -factor_b);
    }
    if(factor_a == 0 || factor_b == 0) {
        // std::cout << "nada";
        return 0;
    }
    if(factor_a == 1) {
        // std::cout << "returning ";
        return factor_b;
    }
    else {
        // std::cout << " * ";
        return factor_b + recursive_function(factor_a -1, factor_b);
    }
}

int recursion_helper (int factor_a, int factor_b) {
    int result = recursive_function(factor_a, factor_b);
    // std::cout << std::endl;
    return result;
}

bool test_recursive_function() {
    // setup
    int test_1_a = 5;
    int test_1_b = 4;
    int test_1_expected_result = 20;

    int test_2_a = -10;
    int test_2_b = 5;
    int test_2_expected_result = -50;

    int test_3_a = 5;
    int test_3_b = -5;
    int test_3_expected_result = -25;

    int test_4_a = -15;
    int test_4_b = -2;
    int test_4_expected_result = 30;

    int test_5_a = 0;
    int test_5_b = -2;
    int test_5_expected_result = 0;

    int test_6_a = 1;
    int test_6_b = 0;
    int test_6_expected_result = 0;

    // execution
    int test_1_result = recursion_helper(test_1_a, test_1_b);
    int test_2_result = recursion_helper(test_2_a, test_2_b);
    int test_3_result = recursion_helper(test_3_a, test_3_b);
    int test_4_result = recursion_helper(test_4_a, test_4_b);
    int test_5_result = recursion_helper(test_5_a, test_5_b);
    int test_6_result = recursion_helper(test_6_a, test_6_b);

    //validation
    // std::cout << "Test 1: " << test_1_result << " expected " << test_1_expected_result << std::endl; 
    assert(test_1_expected_result == test_1_result);
    // std::cout << "Test 2: " << test_2_result << " expected " << test_2_expected_result << std::endl;
    assert(test_2_expected_result == test_2_result);
    // std::cout << "Test 3: " << test_3_result << " expected " << test_3_expected_result << std::endl;
    assert(test_3_expected_result == test_3_result);
    // std::cout << "Test 4: " << test_4_result << " expected " << test_4_expected_result << std::endl;
    assert(test_4_expected_result == test_4_result);
    // std::cout << "Test 5: " << test_5_result << " expected " << test_5_expected_result << std::endl;
    assert(test_5_expected_result == test_5_result);
    // std::cout << "Test 6: " << test_6_result << " expected " << test_6_expected_result << std::endl;
    assert(test_6_expected_result == test_6_result);

    // clean up
    return true;
}

int calculate_power_recursive(int base, int exponent);
int caclulate_power_helper(int base, int exponent);
bool test_calculate_power();

int calculate_power_recursive(int base, int exponent) {
    // base cases
    if (exponent == 0) {
        return 1; // any number to the power of 0 is 1
    }
    if (exponent == 1) {
        return base; // any number to the power of 1 is the number
    }

    // recursive case = base * base^(exponent - 1)
    return base * calculate_power_recursive(base, exponent - 1);
}

int calculate_power_helper(int base, int exponent) {
    if (exponent < 0) {
        std::cout << "cant handle negative exponents" << std::endl;
        return 0; // default return 0 if exponent input is negative
    }
    return calculate_power_recursive(base, exponent);
}

bool test_calculate_power() {
    // setup
    int test_1_base = 5;
    int test_1_exponent = 3;
    int test_1_expected = 125;

    int test_2_base = 2;
    int test_2_exponent = 6;
    int test_2_expected = 64;

    int test_3_base = 4;
    int test_3_exponent = 1;
    int test_3_expected = 4;

    int test_4_base = 7;
    int test_4_exponent = 0;
    int test_4_expected = 1;

    int test_5_base = -1;
    int test_5_exponent = 3;
    int test_5_expected = -1;

    int test_6_base = 3;
    int test_6_exponent = -1;
    int test_6_expected = 0; // anything to negative power defaults to output 0

    // execution 
    int test_1_result = calculate_power_helper(test_1_base, test_1_exponent);
    int test_2_result = calculate_power_helper(test_2_base, test_2_exponent);
    int test_3_result = calculate_power_helper(test_3_base, test_3_exponent);
    int test_4_result = calculate_power_helper(test_4_base, test_4_exponent);
    int test_5_result = calculate_power_helper(test_5_base, test_5_exponent);
    int test_6_result = calculate_power_helper(test_6_base, test_6_exponent);

    // validation
    assert(test_1_expected == test_1_result);
    assert(test_2_expected == test_2_result);
    assert(test_3_expected == test_3_result);
    assert(test_4_expected == test_4_result);
    assert(test_5_expected == test_5_result);
    assert(test_6_expected == test_6_result);

    // cleanup
    return true;
}


int main() {
    test_recursive_function();
    test_calculate_power();
    return 0;
}