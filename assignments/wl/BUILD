cc_library(
    name = "lexicon",
    srcs = ["lexicon.cpp"],
    hdrs = ["lexicon.h"],
    deps = [],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = ["words.txt"],
    deps = [
        ":lexicon",
        ":word_ladder",
    ],
)

cc_library(
    name = "word_ladder",
    srcs = ["word_ladder.cpp"],
    hdrs = ["word_ladder.h"],
    deps = [
        ":lexicon",
    ],
)

cc_test(
    name = "word_ladder_test",
    srcs = ["word_ladder_test.cpp"],
    deps = [
        ":word_ladder",
        "//:catch",
    ],
)
