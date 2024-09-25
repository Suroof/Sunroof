package com.first.sys.repository;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.first.sys.entity.UserInfo;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface UserInfoRepository extends BaseMapper<UserInfo> {
// 不需要定义具体的方法，BaseMapper 已经提供了 CRUD 操作
}