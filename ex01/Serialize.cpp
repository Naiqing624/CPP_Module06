/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:01:01 by marvin            #+#    #+#             */
/*   Updated: 2025/05/07 15:01:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"

Serialize::Serialize() {}

Serialize::~Serialize() {}

Serialize::Serialize(const Serialize &other)
{
	*this = other;
}
Serialize &Serialize::operator=(const Serialize &other)
{
	(void)other;
	return (*this);
}

uintptr_t	Serialize::serialize(Data *ptr)
{
	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data	*Serialize::deserialize(uintptr_t raw)
{
	Data	*ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}


// uintptr_t raw = reinterpret_cast<uintptr_t>(dataPtr);      // 序列化
// //dataPtr 是一个 Data* 类型的指针；
// // uintptr_t 是一个能装下任何指针的无符号整数类型；
// // 这一步把地址（比如 0x7ffee4c3）变成整数（比如 140732814168800）；
// // 目的：让你可以传、存、打印、传送这个值。

// Data* ptr = reinterpret_cast<Data*>(raw);                  // 反序列化
// // 你拿回那个整数（比如 140732814168800）；
// // 告诉编译器：“这是个 Data* 类型的地址！”
// // 然后你就能访问 ptr->x、ptr->s，像原来一样了！

// // ✨ 这个转换只安全 当你在同一个进程中使用；
// // ❌ 如果你程序已经把原来那块内存释放了，再反序列化就会出 bug；
// // ❌ 不能跨机器、跨程序、跨时间存这个地址（因为地址可能变）；
