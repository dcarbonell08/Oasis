//
// Created by Matthew McCall on 5/2/24.
//

#include "Oasis/Summation.hpp"
#include "Oasis/Add.hpp"
#include "Oasis/Divide.hpp"
#include "Oasis/Integral.hpp"
#include "Oasis/Log.hpp"
#include "Oasis/Matrix.hpp"
#include "Oasis/Multiply.hpp"
#include "Oasis/RecursiveCast.hpp"
#include "Oasis/Variable.hpp"

namespace Oasis {

    Summation<Expression>::Summation(const Expression& operand, const Expression& incrementingVar, const Expression& lower, const Expression& upper)
        : BoundedBinaryExpression(operand,incrementingVar,lower,upper)
    {
    }

    auto Summation<Expression>::Simplify() const -> std::unique_ptr<Expression>
    {
        const auto simplifiedOp = mostSigOp ? mostSigOp->Simplify() : nullptr;
        const auto simplifiedInc = leastSigOp ? leastSigOp->Simplify() : nullptr;

        auto Oasis::Add result{
            Oasis::Real{0},
            Oasis::Real{0}
        };

        for(lower, lower < upper; lower += incrementingVar) {
            auto resultant = Oasis::Add{result.Simplify(), lower};
        }    

        return resultant;
    }

} // Oasis