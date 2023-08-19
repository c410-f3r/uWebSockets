#include "App.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        exit(1);
    }

    struct PerSocketData {};

    uWS::App().ws<PerSocketData>("/*", {
        .compression = uWS::DISABLED,
        .maxPayloadLength = 100 * 1024 * 1024,
        .idleTimeout = 16,
        .maxBackpressure = 100 * 1024 * 1024,
        .closeOnBackpressureLimit = false,
        .resetIdleTimeoutOnSend = false,
        .sendPingsAutomatically = true,
        .message = [](auto *ws, std::string_view message, uWS::OpCode opCode) {
            ws->send(message, opCode, false);
        },
    })
    .listen(atoi(argv[1]), [](auto */*listen_socket*/) {})
    .run();
}
