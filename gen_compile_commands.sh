#!/bin/bash

set -e

RELEASE_VERSION=0.3.5
DIRECTORY=./bazel-compilation-database-${RELEASE_VERSION}
OPTS="--show_progress --show_loading_progress"

# download compilation database generator if necessary
if [ ! -d "${DIRECTORY}" ]; then
    curl -L https://github.com/grailbio/bazel-compilation-database/archive/${RELEASE_VERSION}.tar.gz | tar -xz
fi

# generate the compilation database
if command -v clang >/dev/null 2>&1; then
    # clang is most useful (clang-tools, clangd etc.) so default to that compiler's flags
    CC=clang ${DIRECTORY}/generate.sh ${OPTS}
else
    # clang is not installed; just in case, though, we'll
    # ignore GCC specific warnings so clang-tidy and such can run
    ${DIRECTORY}/generate.sh ${OPTS} --copt=-Wno-unknown-warning-option
    # remove -fno-canonical-system-headers, as this is unrecognised by clang-tools
    # could replace with -no-canonical-prefixes for clang support, but seems to work regardless
    sed -i -E 's/\s+-fno-canonical-system-headers\b//g' compile_commands.json
fi
