cc_binary(
    name = "bookstore_main",
    srcs = ["bookstore_main.cpp"],
    deps = [
        ":bookstore",
    ],
)

cc_library(
    name = "bookstore",
    srcs = ["bookstore.cpp"],
    hdrs = ["bookstore.h"],
    deps = [],
)

cc_binary(
    name = "constructors",
    srcs = ["constructors.cpp"],
    deps = [],
)

cc_library(
    name = "intarray",
    srcs = ["intarray.cpp"],
    hdrs = ["intarray.h"],
    deps = [],
)

cc_binary(
    name = "intarray_test",
    srcs = ["intarray_test.cpp"],
    deps = [
        ":intarray",
        "//:catch",
    ],
)
