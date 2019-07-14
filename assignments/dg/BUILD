cc_library(
    name = "graph",
    srcs = ["graph.h", "graph.inc"],
    deps = [],
)

cc_binary(
    name = "client",
    srcs = ["client.cpp"],
    deps = [
        ":graph",
    ],
)

cc_test(
    name = "graph_test",
    srcs = ["graph_test.cpp"],
    deps = [
        ":graph",
        "//:catch",
    ],
)
