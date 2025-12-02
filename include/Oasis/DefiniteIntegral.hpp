

#ifndef OASIS_DEFINITEINTEGRAL_HPP
#define OASIS_DEFINITEINTEGRAL_HPP

#include "BinaryExpression.hpp"
#include "BoundedBinaryExpression.hpp"
#include "Expression.hpp"
#include "Real.hpp"

namespace Oasis {

    template<IExpression Integrand, IExpression Differential, IExpression Upper, IExpression Lower>
    class DefiniteIntegral;

    /// @cond 
    template <>
    class DefiniteIntegral<Expression, Expression, Expression, Expression> : public BoundedBinaryExpression<DefiniteIntegral> {
    public:
        DefiniteIntegral() = default;
        DefiniteIntegral(const DefiniteIntegral<Expression,Expression,Expression,Expression>& other) = default;

        DefiniteIntegral(const Expression& integrand,const Expression& differential,const Expression& upper,const Expression& lower);

        [[nodiscard]] auto Simplify() const -> std::unique_ptr<Expression> final;

        EXPRESSION_TYPE(DefiniteIntegral)
        EXPRESSION_CATEGORY(Associative | Commutative)
    };
    /// @endcond 


    /**
     * Documentation WIP
     * 
     * @tparam
     * @tparam
     * @tparam
     * @tparam
     */
    template <IExpression IntegrandT = Expression, IExpression DifferentialT = IntegrandT, IExpression UpperT = Expression, IExpression LowerT = Expression>
    class DefiniteIntegral : public BoundedBinaryExpression<DefiniteIntegral, IntegrandT, DifferentialT, UpperT, LowerT> {
    public:
        DefiniteIntegral() = default;
        DefiniteIntegral(const DefiniteIntegral<IntegrandT, DifferentialT, UpperT, LowerT>& other)
            : BoundedBinaryExpression<DefiniteIntegral, IntegrandT, DifferentialT, UpperT, LowerT>(other)
        {
        }

        DefiniteIntegral(const IntegrandT& integrand, const DifferentialT& differential, const UpperT& upper, const LowerT& lower)
            : BoundedBinaryExpression<DefiniteIntegral, IntegrandT, DifferentialT, UpperT, LowerT>(integrand,differential,upper,lower)
        {
        }

        auto operator=(const DefiniteIntegral& other) -> DefiniteIntegral&  = default;

        EXPRESSION_TYPE(DefiniteIntegral)
        EXPRESSION_CATEGORY(Associative | Commutative)

    };
    
} // namespace Oasis

#endif