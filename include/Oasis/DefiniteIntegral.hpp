//
// Created by Matthew McCall on 4/30/24.
//

#ifndef DEFINITEINTEGRAL_HPP
#define DEFINITEINTEGRAL_HPP

#include "BoundedBinaryExpression.hpp"
#include "Expression.hpp"
#include "Real.hpp"
#include "Integral.hpp"

namespace Oasis {

template <IExpression OperandT, IExpression VariableT, IExpression UpperBoundT, IExpression LowerBoundT>
class DefiniteIntegral;

/// @cond
template <>
class DefiniteIntegral<Expression, Expression, Expression, Expression> : public BinaryExpression<DefiniteIntegral> {
    DefiniteIntegral() = default;
    DefiniteIntegral(const DefiniteIntegral<Expression, Expression, Expression, Expression>& other) = default;

    DefiniteIntegral(const Expression& integrand, const Expression& differential, const Expression& upper, const Expression& lower);

    [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> final;
    // [[nodiscard]] auto Simplify(const Expression& upper, const Expression& lower) const -> std::unique_ptr<Expression> /* final */;

    EXPRESSION_TYPE(DefiniteIntegral)
    EXPRESSION_CATEGORY(Associative | Commutative)
};
/// @endcond

/**
 * Documentation W.I.P
 * @tparam IntegrandT
 * @tparam DifferentialT
 * @tparam Upper
 * @tparam Lower
 */
template <IExpression IntegrandT = Expression, IExpression DifferentialT = IntegrandT, IExpression UpperT = Expression, IExpression LowerT = Expression >
class DefiniteIntegral : public BinaryExpression<DefiniteIntegral, IntegrandT, DifferentialT, UpperT, LowerT > {
    public:
        DefiniteIntegral() = default;
        DefiniteIntegral(const Integral<IntegrandT, DifferentialT, UpperT, LowerT>& other)
            : BinaryExpression<DefiniteIntegral, IntegrandT, DifferentialT, UpperT, LowerT>(other)
        {
        }

        DefiniteIntegral(const IntegrandT& integrand, const DifferentialT& differential, const UpperT& upper, const LowerT& lower)
        : BinaryExpression<Integral, IntegrandT, DifferentialT, UpperT, LowerT>(integrand, differential, upper, lower)
        {
        }

        auto operator=(const DefiniteIntegral& other) -> DefiniteIntegral& = default;

        EXPRESSION_TYPE(DefiniteIntegral)
        EXPRESSION_CATEGORY(Associative | Commutative)
}
//class DefiniteIntegral final : BoundedBinaryExpression<DefiniteIntegral, OperandT, VariableT, LowerBoundT, UpperBoundT> { };

} // Oasis

#endif // DEFINITEINTEGRAL_HPP
