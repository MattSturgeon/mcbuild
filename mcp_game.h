#pragma once

#include "ids.h"
#include "gamestate.h"

#include "lh_files.h"

void write_packet(uint8_t *ptr, ssize_t len, lh_buf_t *buf);
void chat_message(const char *str, lh_buf_t *buf, const char *color);

void hole_radar(lh_buf_t *client);
void find_tunnels(lh_buf_t *answer, int l, int h);
void autokill(lh_buf_t *server);
void salt_request(lh_buf_t *server, int x, int y, int z);

void autobuild(lh_buf_t *server);
void clear_autobuild();
void build_request(char **words, lh_buf_t *client);
void build_process(lh_buf_t *client);

int process_message(const char *msg, lh_buf_t *forw, lh_buf_t *retour);
void process_packet(int is_client, uint8_t *ptr, ssize_t len, lh_buf_t *forw, lh_buf_t *retour, int *state);
int handle_async(lh_buf_t *client, lh_buf_t *server);

void process_encryption_request(uint8_t *p, lh_buf_t *forw);
void process_encryption_response(uint8_t *p, lh_buf_t *forw);
void drop_connection();