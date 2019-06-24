cc_library(
    name = "euclidean_vector",
    srcs = ["euclidean_vector.cpp"],
    hdrs = ["euclidean_vector.h"],
    deps = [],
)

cc_binary(
    name = "client",
    srcs = ["client.cpp"],
    deps = [
        ":euclidean_vector",
    ],
)

cc_test(
    name = "euclidean_vector_test",
    srcs = ["euclidean_vector_test.cpp"],
    deps = [
        ":euclidean_vector",
        "//:catch",
    ],
)
