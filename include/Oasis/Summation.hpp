//
// Created by Matthew McCall on 5/2/24.
//

#ifndef OASIS_SUMMATION_HPP
#define OASIS_SUMMATION_HPP

#include "BoundedBinaryExpression.hpp"

namespace Oasis {

template <IExpression OperandT, IExpression IncrementingVat, IExpression LowerBoundT, IExpression UpperBoundT>
    class Summation;

/// @cond 
template <IExpression OperandT, IExpression IncrementingVarT, IExpression LowerBoundT, IExpression UpperBoundT>
class Summation final : public BoundedBinaryExpression<Summation, OperandT, IncrementingVarT, LowerBoundT, UpperBoundT> {

    Summation() = default;
    Summation(const Expression<Expression, Expression, Expression, Expression>& other) = default;

    Summation(const Expression& operand, const Expression& incrementingVar, const Expression& lower, const Expression& upper);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> final;

    EXPRESSION_TYPE(Summation)
    EXPRESSION_CATEGORY(BoundedBinExp)
};
/// @endcond

/**
 * The Summation class acts as the sum of a sequence of numbers.
 * 
 * @section param Parameters:
 * @tparam OperandT The expression to iterate through.
 * @tparam IncrementingVarT The incrementing value of each successive sum.
 * @tparam LowerBoundT The starting index of the summation.
 * @tparam UpperBoundT The final index of the summation.
 */
template <IExpression OperandT = Expression, IExpression IncrementingVarT = Expression, IExpression LowerBoundT = Expression, IExpression UpperBoundT = Expression>
class Summation : public BoundedBinaryExpression<OperandT,IncrementingVarT,LowerBoundT,UpperBoundT> {
public:
    Summation() = default;
    Summation(const Summation<OperandT, IncrementingVarT, LowerBoundT, UpperBoundT>& other) 
        : BoundedBinaryExpression<Summation, OperandT, IncrementingVarT, LowerBoundT, UpperBoundT>(other)
    {
    }

    Summation(const Expression& operand, const Expression& incrementingVar, const Expression& lower, const Expression& upper)
        : BoundedBinaryExpression<Summation,OperandT,IncrementingVarT,LowerBoundT,UpperBoundT>(operand,incrementingVar,lower,upper)
    {
    }


    auto operator=(const Summation& other) -> Summation& = default;

    EXPRESSION_TYPE(Summation)
    EXPRESSION_CATEGORY(BoundedBinExp)
}


} // Oasis

#endif // OASIS_SUMMATION_HPP
