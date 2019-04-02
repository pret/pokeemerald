#ifndef GUARD_MEVENT_SERVER_HELPERS_H
#define GUARD_MEVENT_SERVER_HELPERS_H

void mevent_srv_sub_init(struct mevent_srv_sub *, u32, u32);
void mevent_srv_sub_init_send(struct mevent_srv_sub * manager, u32 ident, const void * src, u32 size);
bool32 mevent_srv_sub_recv(struct mevent_srv_sub * manager);
bool32 mevent_srv_sub_send(struct mevent_srv_sub * manager);
void mevent_srv_sub_init_recv(struct mevent_srv_sub *, u32, void *);

#endif //GUARD_MEVENT_SERVER_HELPERS_H
