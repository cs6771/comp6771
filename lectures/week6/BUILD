cc_binary(
    name = "explicit",
    srcs = ["explicit.cpp"],
    deps = [],
)

cc_binary(
    name = "unwind",
    srcs = ["unwind.cpp"],
    deps = [],
)

cc_binary(
    name = "default",
    srcs = ["default.cpp"],
    deps = [],
)

cc_binary(
    name = "nontype",
    srcs = ["nontype.cpp"],
    deps = [],
)

cc_binary(
    name = "partial",
    srcs = ["partial.cpp"],
    deps = [],
)

cc_binary(
    name = "partial2",
    srcs = ["partial2.cpp"],
    deps = [],
)

cc_binary(
    name = "iwyu",
    srcs = ["iwyu.cpp", "iwyu.h"],
    deps = [],
)

cc_library(
    name = "stack",
    srcs = [],
    hdrs = ["stack.h", "stack.tpp"],
    deps = [],
)

cc_binary(
    name = "stack_main",
    srcs = ["stack.cpp"],
    deps = [
        ":stack",
    ],
)