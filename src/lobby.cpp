#include "lobby.h"

#include <godot_cpp/classes/multiplayer_api.hpp>

Lobby::Lobby() {}

void Lobby::_ready() {
	_connect_multiplayer_signal("peer_connected", "_on_peer_connected");
	_connect_multiplayer_signal("peer_disconnected", "_on_peer_disconnected");
	_connect_multiplayer_signal("connected_to_server", "_on_connected_to_server");
	_connect_multiplayer_signal("connection_failed", "_on_connection_fail");
	_connect_multiplayer_signal("server_disconnected", "_on_server_disconnected");
}

Error Lobby::join_game(const StringName &in_address) {
	StringName address = in_address;
	if (in_address.is_empty() || in_address.is_valid_ip_address()) {
		address = DEFAULT_SERVER_IP;
	}

	Ref<MultiplayerPeer> peer;
	peer.instantiate();
	if (peer.is_null()) {
		return Error::FAILED;
	}

	if (peer.ptr()->create_client(address, PORT) != Error::OK) {
		return Error::FAILED;
	}
}

void Lobby::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_on_peer_connected"), &Lobby::_on_peer_connected);
	ClassDB::bind_method(D_METHOD("_on_peer_disconnected"), &Lobby::_on_peer_disconnected);
	ClassDB::bind_method(D_METHOD("_on_connected_to_server"), &Lobby::_on_connected_to_server);
	ClassDB::bind_method(D_METHOD("_on_connection_fail"), &Lobby::_on_connection_fail);
	ClassDB::bind_method(D_METHOD("_on_server_disconnected"), &Lobby::_on_server_disconnected);
}

void Lobby::_connect_multiplayer_signal(const StringName &in_signal_name, const StringName &in_method_name) {
	if (!get_multiplayer().is_valid()) {
		return;
	}
	get_multiplayer().ptr()->connect(in_signal_name, Callable(this, in_method_name));
}
