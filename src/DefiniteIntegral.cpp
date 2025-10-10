//
// Created by Matthew McCall on 4/30/24.
//

#include "Oasis/DefiniteIntegral.hpp"
#include "Oasis/Integral.hpp"

namespace Oasis {
    
    Integral<Expression>::IntegrateWithBounds(const Expression& integrand, const Expression& differential, const Expression& upper, const Expression& lower) const -> std::unique_ptr<Expression>
    {
        /*
        Dependencies:
            Oasis::Integral
            Oasis::Subtract
        */


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

        /*
            Dummy values for now.
        */
        Oasis::Subtract answer {
            *upperBoundSubstituted,
            *lowerBoundSubstituted
        };

       return answer;
    }


} // Oasis