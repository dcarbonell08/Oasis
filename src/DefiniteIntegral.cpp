//
// Created by Matthew McCall on 4/30/24.
// Modified by Djan Carbonell on 10/07/25.
//

#include "Oasis/DefiniteIntegral.hpp"
#include "Oasis/Integral.hpp"
#include "Oasis/Subtract.hpp"


namespace Oasis {
    
    /**
     * Integral<Expression>::IntegrateWithBounds(const Expression& integrand, const Expression& differential, const Expression& upper, const Expression& lower) const -> std::unique_ptr<Expression>
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
     */
    Integral<Expression>::IntegrateWithBounds(const Expression& integrand, const Expression& differential, const Expression& upper, const Expression& lower) const -> std::unique_ptr<Expression>
    {
        /*
        Dependencies:
            Oasis::Integral
            Oasis::Subtract
            Simplify Method
        */

        // Call indefinite integral to evaluate.
        Oasis::Integral interm {
            *integrand,
            *differential
        };

        /*
            Currently evaluates the integral twice.
            Need to look into way how to integrate only once and
            copy values over.
        */
        auto upperBound = interm.Simplify();
        auto lowerBound = interm.Simplify();

        // Substitute upper and lower bounds into evaluated integrals.
        auto subUpperBound = upperBound->Substitute(differential, upper);
        auto subLowerBound = lowerBound->Substitute(differential, lower);

        // Subtract the upper bounds and lower bounds.
        Oasis::Subtract answer {
            *subUpperBound,
            *subLowerBound
        };

       // Return answer
       return answer;
    }
} // Oasis