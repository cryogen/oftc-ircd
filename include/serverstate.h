struct server_state
{
  const char *config_path;
};

void serverstate_set_config_path(const char *);
const char *serverstate_get_config_path();
