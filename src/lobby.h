#pragma once

#include "player_info.h"
#include <godot_cpp/classes/node.hpp>

using namespace godot;

const int PORT = 7000;
const StringName DEFAULT_SERVER_IP = "127.0.0.1";
const int MAX_PEERS = 1;

class Lobby : public Node {
	GDCLASS(Lobby, Node);

public:
	Lobby();
	virtual void _ready() override;
	Error join_game(const StringName &in_address = StringName());
	Error create_game();

protected:
	static void _bind_methods();

	// RPC methods
	void load_game(const StringName &in_scene);
	void player_ready();
	void set_players();

private:
	void _create_player();
	void _connect_multiplayer_signal(const StringName &in_signal_name, const StringName &in_method_name);

	// Signal methods
	void _on_peer_connected();
	void _on_peer_disconnected();
	void _on_connected_to_server();
	void _on_connection_fail();
	void _on_server_disconnected();

	TypedArray<PlayerInfo> players;
};
