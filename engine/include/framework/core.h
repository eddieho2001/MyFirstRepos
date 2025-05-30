#include<memory>

namespace ly {
	//declared unique as nickname as unique pointer
	template<typename T>
	using unique = std::unique_ptr<T>;

	template<typename T>
	using shared = std::shared_ptr<T>;

	template<typename T>
	using weak = std::weak_ptr<T>;

	template<typename T>
	using List = std::vector<T>;

	
}