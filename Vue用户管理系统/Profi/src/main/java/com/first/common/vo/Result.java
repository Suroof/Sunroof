package com.first.common.vo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
//前端接收数据
@Data
@NoArgsConstructor
@AllArgsConstructor
public class Result<T> {
    private Integer code;
    private String msg;
    private T data;

//成功返回
    public static <T> Result<T> success(){
        return new Result<T>(200,"success",null);
    }
    public static <T> Result<T> success(T data,String msg){
        return new Result<T>(200,msg,data);
    }
    public static <T> Result<T> success(String msg){
        return new Result<T>(200,msg,null);
    }
//失败返回
    public static <T> Result<T> fail() {
        return new Result<>(20001, "fail", null);
    }

    public static <T> Result<T> fail(Integer code) {
        return new Result<>(code, "fail", null);
    }

    public static <T> Result<T> fail(Integer code, String message) {
        return new Result<>(code, message, null);
    }

    // 注意：这个方法的定义需要调整，因为Java不支持直接传递命名参数
    // 但我们可以按照位置传递参数，并假设默认code为20001
    public static <T> Result<T> fail(String message) {
        return new Result<>(20001, message, null);
    }
}
