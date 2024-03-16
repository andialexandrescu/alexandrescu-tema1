#include <Reservation.h>
#include <string>
#include <iostream>

Reservation::Reservation(const User &host_user, const User &tenant_user) : host_user(host_user), tenant_user(tenant_user) {}
