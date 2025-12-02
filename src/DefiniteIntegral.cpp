//
// Created by Matthew McCall on 4/30/24.
// Modified by Djan Carbonell on 10/07/25.
//

#include "Oasis/DefiniteIntegral.hpp"
//#include "Oasis/BoundedBinaryExpression.hpp"
#include "Oasis/Integral.hpp"
#include "Oasis/Subtract.hpp"
#include "Oasis/InFixSerializer.hpp"


namespace Oasis {

    DefiniteIntegral<Expression>::DefiniteIntegral(const Expression& integrand, const Expression& differential, const Expression& upper, const Expression& lower)
    // : BoundedBinaryExpression(integrand, differential, lower, upper)
    {
        Oasis::Integral in {
            integrand,
            differential
        };
        auto u = upper;
        auto l = lower;
    }

    auto DefiniteIntegral<Expression>::Simplify() const -> std::unique_ptr<Expression>
    {
        auto up = in.Simplify();
        auto lo = in.Simplify();

        auto upperBound = up->Substitute(differential, u);
        auto lowerBound = lo->Substitute(differential, l);

        Oasis::Subtract finalVal {
            *upperBound,
            *lowerBound
        }

        auto resultant = finalVal;

        return resultant;
    }
    /**
     * DefiniteIntegral<Expression>::IntegrateWithBounds(const Expression& integrand, const Expression& differential, const Expression& upper, const Expression& lower) const -> std::unique_ptr<Expression>
     * -------------------
     * Evaluates an expression into its integral then evaluates the integral based on its bounds.
     * 
     * Arguments:
     * ----------
     * integrand - The expression that will be evaluated.
     * differential - The variable to integrate by.
     * upper - The upper bound of the integral.
     * lower - The lower bound of the integral.
     * 
     * Example usage:
     * std::string exp = {"x+5"};
     * 
     * const auto preproc = Oasis::PreProcessInFix(exp);
     * auto midResult = Oasis::FromInFix(preproc);
     * 
     * const std::unique_ptr<Oasis::Expression> expression = std::move(midResult).value();
     * 
     * Oasis::DefiniteIntegral in {
     *    *expression,
     *    Oasis::Variable{"x"},
     *    Oasis::Real{ 5 },
     *    Oasis::Real{ 2 }
     * };
     * Oasis::InFixSerializer result;
     * 
     * auto answer = in.Simplify();
     * std::println("Result of definite integral: {}", answer->Accept(result).value());
     * 
     * Notes:
     * ------
     * C is a reserved value and should not be passed into the function as a variable. It is used as the constant C in integration.
     */
} // Oasis

/* Need to include Visitor overloaded functions */
/* Need to overload TypedVisit functions */

