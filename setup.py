import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块

    Linux需要编译封装接口
    Windows直接使用预编译的pyd即可
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() != "Linux":
        return []

    compiler_flags = [
        "-std=c++17",
        "-O3",
        "-Wno-delete-incomplete", "-Wno-sign-compare",
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dirs = ["$ORIGIN"]

    vnsipmd = Extension(
        "vnpy_hft.api.sip.vnsipmd",
        [
            "vnpy_hft/api/sip/vnsip/vnsipmd/vnsipmd.cpp",
        ],
        include_dirs=["vnpy_hft/api/sip/include",
                      "vnpy_hft/api/sip/vnsip"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_hft/api/sip/libs", "vnpy_hft/api/sip"],
        libraries=["libhft_trader_api"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vnhfttd = Extension(
        "vnpy_hft.api.hft.vnhfttd",
        [
            "vnpy_hft/api/hft/vnhft/vnhfttd/vnhfttd.cpp",
        ],
        include_dirs=["vnpy_hft/api/hft/include",
                      "vnpy_hft/api/hft/vnhft"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_hft/api/hft/libs", "vnpy_hft/api/hft"],
        libraries=["libhft_trader_api"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnhfttd, vnsipmd]


setup(
    ext_modules=get_ext_modules(),
)
