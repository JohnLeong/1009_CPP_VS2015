#pragma once
#ifndef MACROS_H
#define MACROS_H

#define GETTER(T, C, a, A)\
T C::get##A() { return this->a; }

#define SETTER(T, C, a, A)\
void C::set##A(const T a) { this->a = a; }

#define PV_GET_SET(T, C, a, A) \
private:\
T a;\
public:\
GETTER(T, C, a, A)\
SETTER(T, C, a, A)

#define PRT_GET_SET(T, C, a, A) \
protected:\
T a; \
public:\
GETTER(T, C, a, A)\
SETTER(T, C, a, A)




#endif