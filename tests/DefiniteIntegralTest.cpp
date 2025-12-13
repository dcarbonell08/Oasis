#include "catch2/catch_test_macros.hpp"

#include "Oasis/Add.hpp"
#include "Oasis/Divide.hpp"
#include "Oasis/Exponent.hpp"
#include "Oasis/Multiply.hpp"
#include "Oasis/Real.hpp"
#include "Oasis/Subtract.hpp"
#include "Oasis/Variable.hpp"
#include "Oasis/DefiniteIntegral.hpp"


/*
    Test cases are following the same ones found in IntegrateTests with bounds.
*/

TEST_CASE("Integrate Nonzero number, Bounds 5 and 2", "[Integrate][Real][Nonzero]")
{
    /*
        Base case: 5
    */
    Oasis::Real exp{ 2.0f };


    /*
        Integral should be: 5x + C
    Final results should be: 15
    */
    Oasis::DefiniteIntegral in {
        exp,
        Oasis::Variable{"x"},
        Oasis::Real{ 5 },
        Oasis::Real{ 2 }
    };

    Oasis::Variable var{"x"};

    Oasis::Real result{ 15.0 };

    auto defIntegrated = in.IntegrateWithBounds(in, var, 5, 2);
    REQUIRE(result.Equals(*defIntegrated));
}

TEST_CASE("Integrate Nonzero number, Bounds 10 and 5", "[Integrate][Real][Nonzero]")
{
    /*
        Base case: 5
    */
    Oasis::Real exp{ 2.0f };


    /*
        Integral should be: 5x + C
        Final results should be: 25
    */
    Oasis::DefiniteIntegral in {
        exp,
        Oasis::Variable{"x"},
        Oasis::Real{ 10 },
        Oasis::Real{ 5 }
    };

    Oasis::Variable var{"x"};

    Oasis::Real result{ 25.0 };

    auto defIntegrated = in.IntegrateWithBounds(in, var, 10, 5);
    REQUIRE(result.Equals(*defIntegrated));
}

TEST_CASE("Integrate zero number, Bounds 5 and 0", "[Integrate][Real][Nonzero]")
{
    /*
        Base case: 5
    */
    Oasis::Real exp{ 2.0f };


    /*
        Integral should be: 5x + C
        Final results should be: 15
    */
    Oasis::DefiniteIntegral in {
        exp,
        Oasis::Variable{"x"},
        Oasis::Real{ 5 },
        Oasis::Real{ 0 }
    };

    Oasis::Variable var{"x"};

    Oasis::Real result{ 15.0 };

    auto defIntegrated = in.IntegrateWithBounds(in, var, 5, 2);
    REQUIRE(result.Equals(*defIntegrated));
}

TEST_CASE("Integrate with same bounds, Bounds 2 and 2", "[Integrate][Real][Zero]")
{
    Oasis::Real exp{ 5.0f };

    /*
        Integral should be: 5x + C
        Final results should be: 0
    */
    Oasis::DefiniteIntegral in {
        exp,
        Oasis::Variable{"x"},
        Oasis::Real{ 2 },
        Oasis::Real{ 2 }
    };

    Oasis::Variable var{"x"};

    Oasis::Real result{ 0.0 };

    auto defIntegrated = in.IntegrateWithBounds(in, var, 2, 2);
    REQUIRE(result.Equals(*defIntegrated));
    
}

TEST_CASE("Integrate with upper bound < lower bound, Bounds 2 and 5","[Integrate][Real][Zero]")
{

    Oasis::Real exp{ 5.0f };

    /*
        Integral should be: 5x + C
        Final results should be: -15
    */
    Oasis::DefiniteIntegral in {
       exp,
       Oasis::Variable{"x"},
        Oasis::Real{2},
        Oasis::Real{5}
    };

    Oasis::Variable var{"x"};

    Oasis::Real result{ -15.0 };

    auto defIntegrated = in.IntegrateWithBounds(in, var, 2, 5);
    REQUIRE(result.Equals(*defIntegrated));

}