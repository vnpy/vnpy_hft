def run_generate(filepath: str) -> None:
    """将多行的回调函数合并回一行"""
    callback_prefix = "virtual void On"
    callback_suffix = "{}"

    function_prefix = "virtual int "
    function_suffix = " = 0;"

    with open(filepath, encoding="UTF8") as f_read:
        with open(filepath.replace("_api", "_api_new"), encoding="UTF8", mode="w") as f_write:
            in_callback = False
            in_function = False

            buf = []

            for line in f_read.readlines():
                # 回调处理
                if callback_prefix in line:
                    in_callback = True
                elif function_prefix in line:
                    in_function = True

                if in_callback or in_function:
                    buf.append(line.strip())
                else:
                    f_write.write(line)

                if in_callback and callback_suffix in line:
                    in_callback = False
                    f_write.write("    " + " ".join(buf) + "\n")
                    buf.clear()
                elif in_function and function_suffix in line:
                    in_function = False
                    f_write.write("    " + " ".join(buf) + "\n")
                    buf.clear()


if __name__ == "__main__":
    run_generate("../include/hft/hft_option_trader_api.h")

    run_generate("../include/hft/hft_trader_api.h")
