#ifndef CANDY_FUNCTION_H
#define CANDY_FUNCTION_H

CANDY_NAMESPACE_BEGIN

template<typename>
class Function;

template<typename RetType,typename ...ArgTypes>
class Function<RetType(ArgTypes...)>
{
	class HolderBase;
	using HolderPtrType = std::unique_ptr<HolderBase>;
	class HolderBase
	{
	public:
		virtual ~HolderBase() = default;
		virtual RetType invoke(ArgTypes... _args) = 0;
		virtual void copy(HolderPtrType& _other) = 0;
	};
	template<typename F>
	class Holder :public HolderBase
	{
	public:
		Holder(F _f) :f{ _f } {}

		RetType invoke(ArgTypes... _args)override
		{
			f(std::forward<ArgTypes>(_args)...);
		}
		void copy(HolderPtrType& _other)override
		{
			_other = std::make_unique<HolderBase>(new Holder<F>(f));
		}
	private:
		F f;
	};

public:
	explicit Function() = default;
	~Function() = default;
	Function(const Function&);
	Function& operator=(const Function&);
	Function(Function&&);
	Function& operator=(Function&&);
	template<typename F>
	Function(F _f);
	template<typename F>
	Function& operator=(F _f);

	RetType operator()(ArgTypes... _args);

private:
	template<typename F>
	void createHolder(F _f);

	HolderPtrType m_pHolder;
};

CANDY_NAMESPACE_END

#include "Function.inl"

#endif // CANDY_FUNCTION_H
