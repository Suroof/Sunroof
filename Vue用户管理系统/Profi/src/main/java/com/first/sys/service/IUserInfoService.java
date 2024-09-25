package com.first.sys.service;

import com.first.sys.entity.UserInfo;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;
import java.util.Map;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author baomidou
 * @since 2024-09-12
 */
public interface IUserInfoService {
    List<UserInfo> list(); // 查询所有用户
    UserInfo getUserById(Long id); // 根据ID查询用户
    boolean createUser(UserInfo userInfo); // 新增用户
    boolean updateUser(UserInfo userInfo); // 更新用户
    boolean deleteUser(Long id); // 删除用户
    Map<String, Object> login(UserInfo userInfo); // 用户登录
}
