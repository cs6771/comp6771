cc_library(
    name = "car",
    srcs = ["car.cpp"],
    hdrs = ["car.h"],
    deps = [],
)

cc_binary(
    name = "car_main",
    srcs = ["car_main.cpp"],
    deps = [
        ":car",
    ],
)

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

