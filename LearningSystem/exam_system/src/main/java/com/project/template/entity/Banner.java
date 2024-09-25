package com.project.template.entity;

import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotBlank;

/**
 * 功能：
 * 作者：程序员瑞哥
 */
@Getter
@Setter
public class Banner extends BaseEntity{

    //    @NotBlank
    private String name;

    private String img;

    private String link;

}