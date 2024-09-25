package com.project.template.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import lombok.Getter;
import lombok.Setter;

/**
 * 功能：
 * 作者：程序员瑞哥
 */
@Getter
@Setter
public class ExamQuestion extends BaseEntity{

    private String name;
    private String type;
    private String options;
    private String answer;
    private Integer score;
    private Integer userId;

    //通过userid来获取老师信息
    @TableField(exist = false)
    private String user;

}