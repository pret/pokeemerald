#ifndef GUARD_MEVENT_SERVER_ISH_H
#define GUARD_MEVENT_SERVER_ISH_H

void mevent_srv_ish_do_init(u32 arg);
u32 mevent_srv_ish_do_exec(u16 * a0);
void mevent_srv_ish_inc_flag(void);
void * mevent_srv_ish_get_buffer(void);
void mevent_srv_ish_set_param(u32 a0);

#endif //GUARD_MEVENT_SERVER_ISH_H
