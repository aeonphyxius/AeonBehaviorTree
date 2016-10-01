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


}
#endif /* UTILS_H */