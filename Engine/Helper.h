#pragma once


// 评估 HRESULT 的宏，常用于 DirectX 开发
#define GM_EVAL_HR(hr, error) \
    if ((hr) != S_OK) { \
        std::cout << "API Error: " << error << " At file: " << __FILE__ << std::endl; \
    }

// 调试模式下的断言宏
#ifdef _DEBUG
#define GM_ASSERT(exp) \
        if (!(exp)) { \
            std::cout << "Critical error in file: " << __FILE__ << " at line: " << __LINE__ << std::endl; \
            throw; \
        }
#else
    // Release 模式下宏会被替换为空，不占用任何性能
#define GM_ASSERT(exp)
#endif

#define PRINT_W_N(messsage) std::wcout << messsage << std::endl;
#define PRINT_N(messsage) std::ccout << messsage << std::endl;