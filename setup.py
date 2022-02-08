from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块

    Windows需要编译封装接口
    Linux和Mac由于缺乏二进制库支持无法使用
    """
    extra_compile_flags = ["-O2"]
    extra_link_args = []
    runtime_library_dirs = []

    vnsipmd = Extension(
        "vnpy_hft.api.sip.vnsipmd",
        [
            "vnpy_hft/api/sip/vnsip/vnsipmd/vnsipmd.cpp",
        ],
        include_dirs=["vnpy_hft/api/sip/include",
                      "vnpy_hft/api/sip/include/sip",
                      "vnpy_hft/api/sip/include/sip/header_for_generator",
                      "vnpy_hft/api/sip/vnhft"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_hft/api/sip/libs", "vnpy_hft/api/sip"],
        libraries=["sipuix_x64"],
        extra_compile_args=extra_compile_flags,
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
                      "vnpy_hft/api/hft/include/hft",
                      "vnpy_hft/api/hft/include/hft/header_for_generator",
                      "vnpy_hft/api/hft/vnhft"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_hft/api/hft/libs", "vnpy_hft/api/hft"],
        libraries=["libhft_trader_api"],
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnhfttd, vnsipmd]


setup(
    ext_modules=get_ext_modules(),
)
