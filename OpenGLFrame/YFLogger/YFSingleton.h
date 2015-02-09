#ifndef YF_SINGLETON_H__
#define	YF_SINGLETON_H__ 
#include <assert.h>

namespace YFun
{
	template<typename T>
	class Singleton
	{
	protected:
		Singleton()
		{
			instanceNum++;
			assert(instanceNum <= 1);
		}
		Singleton(const Singleton &);
		Singleton & operator = (const Singleton &);

	public:
		static T &getInstance()
		{
			static T instance;
			return instance;
		}
	private:
		static int instanceNum;
	};

	template<typename T>
	int Singleton<T>::instanceNum = 0;
}

#endif