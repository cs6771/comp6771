cc_binary(
    name = "dictionary",
    srcs = ["dictionary.cpp"],
    data = ["//data:words"],
    deps = [":dictionary_library"],
)

cc_library(
    name = "dictionary_library",
    srcs = ["dictionary_library.cpp"],
    hdrs = ["dictionary_library.h"],
    deps = [],
)

cc_test(
    name = "dictionary_library_test",
    srcs = ["dictionary_library_test.cpp"],
    deps = [
        ":dictionary_library",
        "//:catch",
    ],
)
