#ifndef UTILS_H
#define UTILS_H

namespace Utils
{	

	template<class C, class T>
	inline auto ContainsChild(const C& vector, const T& child)
		-> decltype(end(vector), true)
	{
		return end(vector) != std::find(begin(vector), end(vector), child);
	}
	
	inline void Log()
	{
		std::cout << std::endl;
	}

	template<typename First, typename ... Strings>
	inline void Log(First arg, const Strings&... rest) {
		std::cout << arg << " ";
		Log(rest...);		
	}




}
#endif /* UTILS_H */