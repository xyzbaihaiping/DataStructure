
struct TureType
{
	bool Get()
	{
		return true;
	}
};
struct FalseType
{
	bool Get()
	{
		return false;
	}
};
template<typename T>
struct TypeTraits
{
	typedef FalseType IsPodType;
};
template<>
struct TypeTraits<int>
{
	typedef TureType IsPodType;
};
template<>
struct TypeTraits<char>
{
	typedef TureType IsPodType;
};
template<>
struct TypeTraits<double>
{
	typedef TureType IsPodType;
};
template<>
struct TypeTraits<long>
{
	typedef TureType IsPodType;
};
template<>
struct TypeTraits<long long>
{
	typedef TureType IsPodType;
};
