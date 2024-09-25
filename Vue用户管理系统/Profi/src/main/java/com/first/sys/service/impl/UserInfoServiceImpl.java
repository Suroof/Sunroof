package com.first.sys.service.impl;

import com.first.sys.entity.UserInfo;
import com.first.sys.mapper.UserInfoMapper;
import com.first.sys.service.IUserInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

@Service
public class UserInfoServiceImpl implements IUserInfoService {

    @Autowired
    private UserInfoMapper userInfoMapper;

    @Override
    public List<UserInfo> list() {
        return userInfoMapper.selectAll();
    }

    @Override
    public UserInfo getUserById(Long id) {
        return userInfoMapper.selectById(id);
    }

    @Override
    public boolean createUser(UserInfo userInfo) {
        return userInfoMapper.insert(userInfo) > 0;
    }

    @Override
    public boolean updateUser(UserInfo userInfo) {
        return userInfoMapper.update(userInfo) > 0;
    }

    @Override
    public boolean deleteUser(Long id) {
        return userInfoMapper.delete(id) > 0;
    }

    @Override
    public Map<String, Object> login(UserInfo userInfo) {
        UserInfo user = userInfoMapper.selectByUsernameAndPassword(userInfo.getName().toString(), userInfo.getPassword().toString());
        Map<String, Object> result = new HashMap<>();
        if (user != null) {
            result.put("success", true);
            result.put("user", user);
        } else {
            result.put("success", false);
            result.put("message", "Invalid username or password");
        }
        return result;
    }
}